#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5; 
inline void read(int &a){
	int k=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+(ch-'0');ch=getchar();}
	a=f*k;
}
int T,n,a[N],b[N],c[N];
int t1[N],t2[N],t3[N];
inline bool cmp1(int x,int y){
	int tx=max(b[x],c[x]),ty=max(b[y],c[y]);
	return (a[x]-tx)<(a[y]-ty);	
}
inline bool cmp2(int x,int y){
	int tx=max(a[x],c[x]),ty=max(a[y],c[y]);
	return (b[x]-tx)<(b[y]-ty);	
}
inline bool cmp3(int x,int y){
	int tx=max(b[x],a[x]),ty=max(b[y],a[y]);
	return (c[x]-tx)<(c[y]-ty);	
}
inline void clean(){
	for(int i=1;i<=n;i++){
		a[i]=b[i]=c[i]=0;
		t1[i]=t2[i]=t3[i]=0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		clean();
		int tn=n/2;
		int c1=0,c2=0,c3=0,ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=n;i++)
			read(a[i]),read(b[i]),read(c[i]);
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				t1[++c1]=i;
				ans1+=a[i]; 
			}
			else if(b[i]>a[i]&&b[i]>=c[i]){
				t2[++c2]=i;
				ans2+=b[i]; 
			}
			else if(c[i]>a[i]&&c[i]>b[i]){
				t3[++c3]=i;
				ans3+=c[i];
			}
		}	
		if(c1>tn){
			sort(t1+1,t1+c1+1,cmp1);
			for(int i=1;i<=c1-tn;i++){
				ans1-=a[t1[i]];
				if(b[t1[i]]>=c[t1[i]])
					ans2+=b[t1[i]];
				else ans3+=c[t1[i]]; 
			}
		}
		else if(c2>tn){
			sort(t2+1,t2+c2+1,cmp2);
			for(int i=1;i<=c2-tn;i++){
				ans2-=b[t2[i]];
				if(a[t2[i]]>=c[t2[i]])
					ans1+=a[t2[i]];
				else ans3+=c[t2[i]]; 
			}
		}			
		else if(c3>tn){
			sort(t3+1,t3+c3+1,cmp3);
			for(int i=1;i<=c3-tn;i++){
				ans3-=c[t3[i]];
				if(a[t3[i]]>=b[t3[i]])
					ans1+=a[t3[i]];
				else ans2+=b[t3[i]]; 
			}
		}			
		cout<<ans1+ans2+ans3<<"\n";	
	}
	return 0;
} 
