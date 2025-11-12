#include<bits/stdc++.h>
using namespace std;
int n;
struct suc{
	int s1,s2,s3;
};
suc more[100010];
int tot1=0,tot2=0,tot3=0;
suc a[100010];
vector<int>c1;
vector<int>c2;
vector<int>c3;
int f(long long x){
	long long sqrx=x*x;
	return sqrt(x);
}
long long answ=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",	&a[i].s1,&a[i].s2,
			&a[i].s3);//in
			more[i].s1=a[i].s1-a[i].s2;//c1-c2
			more[i].s2=a[i].s2-a[i].s3;//c2-c3
			more[i].s3=a[i].s1-a[i].s3;//c1-c3
		}//init
		for(int i=1;i<=n;i++){
			int m1=f(more[i].s1);
			int m2=f(more[i].s2);
			int m3=f(more[i].s3);
			int m=max(max(a[i].s1,a[i].s2),max(a[i].s2,a[i].s3));
			int s1=a[i].s1,s2=a[i].s2,s3=a[i].s3;
			int n2=n/2;
			if(m1>m2&&m2>m3){
				if(m==s2){
					if(c2.size()!=n2)c2.push_back(s2);
					else c3.push_back(s3);
				}else{
					if(c3.size()!=n2)c3.push_back(s3);
					else c1.push_back(s1);
				}
			}
			else if(m1>=m3&&m3>m2){
				if(m==s1){
					if(c1.size()!=n2)c1.push_back(s1);
					else c3.push_back(s3);
				}
				else {
					if(c3.size()!=n2)c3.push_back(s3);
					else c2.push_back(s2);
				}
			}
			else if(m3>=m2&&m2>m1){
				if(m==s3){
					if(c3.size()!=n2)c3.push_back(s3);
					else c2.push_back(a[i].s2);
				}
				else {
					if(c2.size()!=n2)c2.push_back(s2);
					else c1.push_back(s1);
				}
			}
			else if(m3>=m1&&m1>m2){
				if(m==s1){
					if(c1.size()!=n2)c1.push_back(s1);
					else c2.push_back(s2);
				}
				else {
					if(c2.size()!=n2)c2.push_back(s2);
					else c3.push_back(s3);
				}
			}
			else if(m2>=m3&&m3>m1){
				if(m==s3){
					if(c3.size()!=n2)c3.push_back(s3);
					else c1.push_back(s1);
				}
				else {
					if(c1.size()!=n2)c1.push_back(s1);
					else c2.push_back(s2);
				}
			}
			else if(m2>=m1&&m2>m3){
				if(m==s2){
					if(c2.size()!=n2)c2.push_back(s2);
					else c1.push_back(s1);
				}
				else{
					if(c1.size()!=n2)c1.push_back(s1);
					else c3.push_back(s3);
				}
			}
			else {//m1==m2==m3
				if(c1.size()<=c2.size()&&c1.size()<=c3.size())c1.push_back(a[i].s1);
				if(c2.size()<=c1.size()&&c2.size()<=c3.size())c1.push_back(a[i].s2);
				if(c3.size()<=c1.size()&&c3.size()<=c1.size())c1.push_back(a[i].s3);
			}
		}
			int siz1=c1.size(),siz2=c2.size(),siz3=c3.size();
	for(int i=0;i<siz1;i++){
		answ+=c1[i];
	}
	for(int i=0;i<siz2;i++){
		answ+=c2[i];
	}
	for(int i=0;i<siz3;i++){
		answ+=c3[i];
	}
	cout<<answ<<endl;/**/
	}
	return 0;
}		/*for(int i=1;i<=n;i++){
			scanf("%d",&ai1[i]);
			scanf("%d",&ai2[i]);
			scanf("%d",&ai3[i]);
		}*/
			/*tot1+=a[i].s1;
			tot2+=a[i].s2;
			tot3+=a[i].s3;*/
//suc a[100010];
/*int ai1[100010],b1[100010];
int ai2[100010],b2[100010];
int ai3[100010],b3[100010];*/
/*bool cmp1(suc a,suc b){
	return a.s1>b.s1;
}
bool cmp2(suc a,suc b){
	return a.s2>b.s2;
}
bool cmp3(suc a,suc b){
	return a.s3>b.s3;
}*/

