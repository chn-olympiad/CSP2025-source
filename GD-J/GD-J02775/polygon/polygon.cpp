#include<bits/stdc++.h>
using namespace std;

int n,a[5010],r=1,aa[5010],ans,ma=1;
string s;
bool fun(int b[],int len) {
	int cnt=0,ma=0;
	for(int i=1;i<=len;i++) {
		ma=max(ma,b[i]);
		cnt+=a[i];
	}
	if(cnt>ma*2) {
		return 1;
	}
	else {
		return 0;
	}
}
void f(int x) {
	while(x>=1) {
		char a=x%2+'0';
		s=a+s;
		x=x/2;
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]!=1) {
			r=0;
		} 
	}
	if(r==1) {
		int cnt=0;
		for(int i=3;i<=n;i++) {
			int x=1;
			for(int j=n;j>=i;j--) {
				x=x*j;
			}
			for(int j=1;j<=i;j++) {
				x=x/j;
			}
			cnt+=x;
		}
		cout<<cnt;
		return 0;
	}
	int len=1<<n;
	for(int i=1;i<=len;i++) {
		int kk=0;
		int x=i;
		s=" ";
		memset(aa,0,sizeof(aa));
		f(x);
		s='0'+s;
		for(int j=1;j<=n;j++) {
			if(s[j]=='1') {
				kk++;
			}
		} 
		if(kk>ma) {
			ma=kk;
		}
		if(kk<ma||kk<3) {
			continue;
		}
		for(int j=1;j<=100;j++) {
			s+='0';
		} 
		int k=1;
		for(int j=1;j<=n;j++) {
			if(s[j]=='1') {
				aa[k]=a[j];
				k++;
			} 
		}
		if(fun(aa,k)) {
			ans++;
		}
	}
	cout<<ans-1;
//#Shang4Shan3Ruo6Shui4
	return 0;
}
