#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e4+5;
int n,k,ans,ci,ma,x,l;
int a[N],b[N],c[N];
bool w[N];
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=b[i-1]^a[i];
		ma=max(ma,a[i]);
		if(a[i]==k) c[++ci]=i;
	}
	if(ma<=1){
		if(k==0&&ma==0) cout<<n<<endl;
		else if(k==0){
			bool q=true;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(q) q=false;
					else{
						q=true;
						ans++;
					}
				}else{
					 ans++;
					 q=true;
				}
			}
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=ci;i++){
		int cnt=0;
		for(int j=c[i-1]+1;j<c[i];j++){
			x=0,l=j+1;
			for(int s=j+1;s<c[i];s++){
				int e=b[s]^b[l-1];
				if(e==k){
					x++;
					l=s+1;
				}
			}
			cnt=max(cnt,x);
		}
		ans+=cnt;
	}
	int r=0;
	for(int i=c[ci]+1;i<=n;i++){
		x=0,l=i+1;
		for(int s=i+1;s<=n;s++){
			int e=b[s]^b[l-1];
			if(e==k){
				x++;
				l=s+1;
			}
		}
		r=max(r,x);
	}
	cout<<ans+ci+r<<endl;
	return 0;
}
