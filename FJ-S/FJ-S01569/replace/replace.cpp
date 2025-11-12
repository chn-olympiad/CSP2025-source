#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
struct lin{
	string a1,a2;
	int l1,r1;
}a[N];
string b1,b2;
bool rev(string x,string y,int lx,int rx,int ly){
	bool tf=1;
	for(int i=lx,j=ly;i<=rx;i++,j++)
		if(x[i]!=y[j]){
			tf=0;
			break;
		}
	return tf;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].a1>>a[i].a2;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].a1.size();j++){
			if(a[i].a1[j]!=a[i].a2[j]){
				a[i].l1=j;
				break;
			}
		}
		for(int j=a[i].a1.size()-1;j>=0;j--){
			if(a[i].a1[j]!=a[i].a2[j]){
				a[i].r1=j;
				break;
			}
		}
	}
	while(q--){
		cin>>b1>>b2;
		int l,r,ans=0;
		for(int i=0;i<b1.size();i++)
			if(b1[i]!=b2[i]){
				l=i;
				break;
			}
		for(int i=b1.size()-1;i>=0;i--)
			if(b1[i]!=b2[i]){
				r=i;
				break;
			}
		for(int i=1;i<=n;i++){
			if(r-l==a[i].r1-a[i].l1 && l>=a[i].l1 && b1.size()-r>=a[i].a1.size()-a[i].r1)
				if(rev(a[i].a1,b1,a[i].l1,a[i].r1,l))
					if(rev(a[i].a2,b2,a[i].l1,a[i].r1,l))
						if(rev(a[i].a1,b1,0,a[i].l1-1,l-a[i].l1))
							if(rev(a[i].a1,b1,a[i].r1+1,a[i].a1.size()-1,r+1))
								ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
