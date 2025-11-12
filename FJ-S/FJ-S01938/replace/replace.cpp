#include <bits/stdc++.h>
using namespace std;

const int N=5*1e6;

int rd() {
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		x=x*10+ch-'0';
		ch=getchar();
	} 
	return x*f; 
}

int n,q,ans;
string s1[N],s2[N]; 
string t1,t2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd(); q=rd(); 
	for(int i=1;i<=n;i++) {
		cin>>s1[i];
		cin>>s2[i]; 
	} 
	while(q--) {
		ans=0;
		cin>>t1>>t2;
		int l=1,r=n;
		for(int i=0;i<t1.size();i++) {
			if(t1[i]!=t2[i]) {l=i; break;}
		}
		for(int i=t1.size()-1;i>=0;i--) {
			if(t1[i]!=t2[i]) {r=i; break;}
		}
		
		string tmp1="",tmp2="",a,b;
		for(int i=l;i<=r;i++) {
			tmp1+=t1[i];
			tmp2+=t2[i]; 
		}
		for(int p=1;p<=n;p++) {
			a=s1[p],b=s2[p];
		//	cout<<a<<' '<<b<<'\n';
			if(r-l+1>a.size()) continue;
			else if(r-l+1==a.size()) {
				if(a==tmp1&&b==tmp2) ans++;
			}
			else {
//				if(r-l+1==a.size()) {
//					if(a==tmp1&&b==tmp2) ans++;
//				///	else continue;
//				}
			
				int j=0;
				for(int i=0;i<a.size();i++) {
			///		cout<<a[i]<<' '<<tmp1[j]<<' '<<b[i]<<' '<<tmp2[j]<<'\n';
					
					if(a[i]==tmp1[j]&&b[i]==tmp2[j]) {
						j++;
					}
					else {
						if(j==tmp1.size()) {
							bool f=1;
							for(int k1=l-1,k2=i-(r-l+1)-1;k2>=0&&f==1;k1--,k2--) {
								if(t1[k1]!=a[k2]) f=0;
								if(t2[k1]!=b[k2]) f=0;
							}
							for(int k1=r+1,k2=i;k2<a.size()&&f==1;k1++,k2++) {
								if(t1[k1]!=a[k2]) f=0;
								if(t2[k1]!=b[k2]) f=0;
							}
							if(f) ans++; 
						}
						j=0;
						// continue;	
					}
				///	cout<<j<<'\n'; 
				}
				
			}
		///cout<<p<<' '<<ans<<'\n'; 
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
