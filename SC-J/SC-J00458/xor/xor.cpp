#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;char c;int f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}
inline void write(int x){
	if(x==0) return ;
	if(x<0) putchar('-'),x=-x;
	write(x/10);
	putchar(x%10+48);
	return ;
}
int n,k;
int kil=0,del=0,big=0;
int ans=0;
int a[500005];
int s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);
		s[i]=(s[i-1]^a[i]);
//		cout<<s[i]<<' ';
	}
//	cout<<'\n';
	for(int i=1;i<=n;i++){
		bool flag=0;
		if((s[i]^kil)==k){
//			cout<<i<<' '<<s[i]<<' '<<kil<<'\n';
			ans++;
			flag=1;
			del=(s[i]^kil);
//			s.erase(s.begin(),s.begin()+i-big);
			big=i;
		}else{
			for(int j=big+1;j<=i;j++){
				if(((s[i]^kil^s[j]^kil)==k&&k!=0)||(k==0&&a[i]==0)){
//					cout<<i<<' '<<j<<' '<<s[i]<<' '<<s[j]<<' '<<(s[i]^s[j])<<' '<<kil<<'\n';
					ans++;
					flag=1;
					del=(s[i]^kil);
//					s.erase(s.begin(),s.begin()+i-big);
					big=i;
					break;
				}
			}
		}
		if(flag) kil^=del;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

