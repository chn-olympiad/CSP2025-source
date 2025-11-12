#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,MX=1e8;
typedef long long LL;
int t,n;
int ans[6];
struct p{
	int a1=0,a2=0,a3=0;//个人满意度
	int go=0;//个人选择
	int c12=0,c13=0,c23=0;//社团满意度差值 
}a[N];
bool cmp(p a,p b){
	return a.a1>b.a1;
}
//priority_queue<int>p;
int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	cin>>t;
	int tt=t;
	while(t--){
		int A=0,B=0;
		int s1=0,s2=0,s3=0;//社团满意度 
		int nb1=0,nb2=0,nb3=0;//社团人数 
		cin>>n;
		const int m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2==a[i].a3&&a[i].a3==0){
				A+=1;
			}
			if(a[i].a3==0){
				B+=1;
			}
			a[i].c12=abs(a[i].a1-a[i].a2);
			a[i].c13=abs(a[i].a1-a[i].a3);
			a[i].c23=abs(a[i].a2-a[i].a3);
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
				a[i].go=1;
				s1+=a[i].a1;
				nb1+=1;
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
				a[i].go=2;
				s2+=a[i].a2;
				nb2+=1;
			}
			else{
				a[i].go=3;
				s3+=a[i].a3;
				nb3+=1;
			}
		}
		if(A==n){
			s1=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=m;i++){
				s1+=a[i].a1;
			}
			cout<<s1<<endl;
			continue;
		}
		int nn=0;
		if(nb1>m){
			nn=nb1-m;
			while(nn--){
				int k=MX,ii=0,c=0;
				for(int i=1;i<=n;i++){
					if(a[i].go==1&&(k>a[i].c12||k>a[i].c13)){
						if(a[i].c12<a[i].c13){
							k=a[i].c12;
							ii=i;
							c=2;
						}
						else{
							k=a[i].c13;
							ii=i;
							c=3;
						}
					}
				}
				s1-=a[ii].a1;
				if(c==2){
					s2+=a[ii].a2;
				}
				else{
					s3+=a[ii].a3;
				}
			}
		}
		else if(nb2>m){
			nn=nb2-m;
			while(nn--){
				int k=MX,ii=0,c=0;
				for(int i=1;i<=n;i++){
					if(a[i].go==2&&(k>a[i].c12||k>a[i].c23)){
						if(a[i].c12<a[i].c23){
							k=a[i].c12;
							ii=i;
							c=1;
						}
						else{
							k=a[i].c23;
							ii=i;
							c=3;
						}
					}
				}
				s2-=a[ii].a2;
				if(c==1){
					s1+=a[ii].a1;
				}
				else{
					s3+=a[ii].a3;
				}
			}
		}
		else if(nb3>m){
			nn=nb3-m;
			while(nn--){
				int k=MX,ii=0,c=0;
				for(int i=1;i<=n;i++){
					if(a[i].go==3&&(k>a[i].c23||k>a[i].c13)){
						if(a[i].c13<a[i].c23){
							k=a[i].c13;
							ii=i;
							c=1;
						}
						else{
							k=a[i].c23;
							ii=i;
							c=2;
						}
					}
				}
				s3-=a[ii].a3;
				if(c==1){
					s1+=a[ii].a1;
				}
				else{
					s2+=a[ii].a2;
				}
			}
		}
		ans[tt-t]=s1+s2+s3;
//		cout<<s1+s2+s3<<'*'<<endl;//
	}
	for(int i=1;i<=tt;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
