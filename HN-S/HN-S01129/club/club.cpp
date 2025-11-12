/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1*/
#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
int n;long long cnt=0;
struct ST{
	int num,d;
	//int nnum;
}a1[N],a2[N],a3[N];
bool v[N];int c1=0,c2=0,c3=0;
bool cmp(ST x,ST y){
	return x.d>y.d||(x.d==y.d&&x.num<y.num);
} 
int moyi(){
	cin>>n;
	//初始化 
	if(n==2){//测试点一
	cnt=0;
		int x[5],y[5];
		cin>>x[1]>>x[2]>>x[3]>>y[1]>>y[2]>>y[3];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					cnt=max(int(cnt),x[i]+y[j]);
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	
	for(int i=1;i<=N;i++){
		a1[i].d=0;a2[i].d=0;a3[i].d=0;
		v[i]=0;
		a1[i].num=0;a2[i].num=0;a3[i].num=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a1[i].d>>a2[i].d>>a3[i].d;
		a1[i].num=i;a2[i].num=i;a3[i].num=i;
	}
	sort(a1+1,a1+n+1,cmp);
	sort(a2+1,a2+n+1,cmp);
	sort(a3+1,a3+n+1,cmp);
	/*for(int i=1;i<=n;i++){
		a1[i].nnum=i;a2[i].nnum=i;a2[i].nnum=i;
	}*/
	/*for(int i=1;i<=n;i++) cout<<a1[i].d<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<a2[i].d<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<a3[i].d<<" ";
	cout<<endl;*/
	
	cnt=0;c1=0;c2=0;c3=0;
	int maxs=n/2;
	for(int i=1;i<=n;i++){
		//cout<<i<<endl; 
		//先判断是否已满
		//if(c1>=maxs&&c2>=maxs&&c3>=maxs) break;
		if(a1[i].num==a2[i].num&&a1[i].num==a3[i].num){//排名相同找更大 
			if(a1[i].d>=a2[i].d&&a1[i].d>=a3[i].d&&c1<maxs){
				cnt+=a1[i].d;
				c1++;
				//三者相同不标记 
			}else if(a2[i].d>a1[i].d&&a2[i].d>a3[i].d&&c2<maxs){
				cnt+=a2[i].d;
				c2++;
			}else if(c3<maxs){
				cnt+=a3[i].d;
				c3++;
			}
		}
		
		
		else if(a1[i].num==a2[i].num){//一二相同 
			if(v[a3[i].num]==0&&c3<maxs){
				v[a3[i].num]=1;
				c3++;
				cnt+=a3[i].d;
			}
			if(a1[i].d>=a2[i].d&&c1<maxs&&v[a1[i].num]==0){
				v[a1[i].num]=1;
				c1++;
				cnt+=a1[i].d;
			}else if(c2<maxs&&v[a2[i].num]==0){
				v[a2[i].num]=1;
				c2++;
				cnt+=a2[i].d;
			}
		}
		
		else if(a3[i].num==a2[i].num){//二三 
			if(v[a1[i].num]==0&&c1<maxs){
				v[a1[i].num]=1;
				c1++;
				cnt+=a1[i].d;
			}
			if(a3[i].d>=a2[i].d&&c3<maxs&&v[a3[i].num]==0){
				v[a3[i].num]=1;
				c3++;
				cnt+=a3[i].d;
			}else if(c2<maxs&&v[a2[i].num]==0){
				v[a2[i].num]=1;
				c2++;
				cnt+=a2[i].d;
			}
		}
		
		else if(a1[i].num==a3[i].num){//一三 
			if(v[a2[i].num]==0&&c2<maxs){
				v[a2[i].num]=1;
				c2++;
				cnt+=a2[i].d;
			}
			if(a1[i].d>=a3[i].d&&c1<maxs&&v[a1[i].num]==0){
				v[a1[i].num]=1;
				c1++;
				cnt+=a1[i].d;
			}else if(c3<maxs&&v[a3[i].num]==0){
				v[a3[i].num]=1;
				c3++;
				cnt+=a3[i].d;
			}
		}
		
		else{//都不同，那个没找找哪个 
			if(v[a2[i].num]==0&&c2<maxs){
				v[a2[i].num]=1;
				c2++;
				cnt+=a2[i].d;
			}
			if(v[a1[i].num]==0&&c1<maxs){
				v[a1[i].num]=1;
				c1++;
				cnt+=a1[i].d;
			}
			if(v[a3[i].num]==0&&c3<maxs){
				v[a3[i].num]=1;
				c3++;
				cnt+=a3[i].d;
			}
		}
		//cout<<cnt<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		moyi();
	}
	return 0;
} 
