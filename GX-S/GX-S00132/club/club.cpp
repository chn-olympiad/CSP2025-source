#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<cstring>
using namespace std;
int t,n,c[4],m[100001];
struct st{
	int id,val,ty;
}a[300011];
bool cmp(st x,st y){
	return x.val>y.val;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int x=0;
		int num=0,ans=0;
		memset(m,0,sizeof(m));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n*3;i+=3){a[i].id=a[i+1].id=a[i+2].id=++x;scanf("%d %d %d",&a[i].val,&a[i+1].val,&a[i+2].val);a[i].ty=1;a[i+1].ty=2;a[i+2].ty=3;}
		sort(a+1,a+n*3+1,cmp);
		//for(int i=1;i<=n*3;i++)cout<<a[i].id<<" "<<a[i].val<<" "<<a[i].ty<<endl;
		//cout<<"|"<<n<<"|"<<endl;
		for(int q=1;q<=n*3;q++){
			if(num==n)break;
			if(!m[a[q].id]&&c[a[q].ty]<n/2){ans+=a[q].val;m[a[q].id]=1;num++;c[a[q].ty]++;}
			//cout<<"Q"<<q<<" "<<a[q].id<<" "<<a[q].val<<" "<<a[q].ty<<endl;
			//cout<<"C"<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
		}
		cout<<ans<<endl;
		//cout<<"-----------------"<<endl;
	}
	return 0;
}
