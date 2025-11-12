#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,sum[3];
struct per{
	int pos,x;
}a[3],d[N];
bool cmp(per a,per b){
	return a.x<b.x;
}
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		int ans=0;
		memset(sum,0,sizeof(sum));
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++) a[j].x=read(),a[j].pos=j;
			sort(a,a+3,cmp);
			int b=a[2].x,c=a[1].x,pb=a[2].pos;
			d[i]={pb,b-c};sum[pb]++,ans+=b;
		}
		int max1=0,k;
		for(int i=0;i<3;i++) if(max1<sum[i]){
			max1=sum[i];k=i;
		}
		//cout<<max1<<" "<<k<<endl;
		if(max1<=n/2){
			cout<<ans<<endl;
		}
		else{
			sort(d+1,d+n+1,cmp);
			int s=0,i=1;
			while(s<=max1-n/2){
				if(d[i].pos==k){
					s++,ans-=d[i].x;
					if(s==max1-n/2) break;
				}
				i++;
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
}
