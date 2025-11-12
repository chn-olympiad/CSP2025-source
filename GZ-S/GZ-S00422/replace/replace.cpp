//GZ-S00422 赵其坤 遵义航天高级中学                                              
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,ans,l,r,k;
string a,b,c,d;
struct node{
	string vc,ve;
}t[N],s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i].vc>>s[i].ve;
	for(int i=1;i<=q;i++)
		cin>>t[i].vc>>t[i].ve;
	for(int i=1;i<=n;i++){
		a=s[i].vc;
		b=s[i].ve;
		r=0;
		l=0;
		k=0;
		for(int j=0;j<s[i].vc.size();j++)
		    if(a[j]!=b[j]){
		    	l=j;
		    	break;
			}
		for(int j=s[i].vc.size()-1;j>=0;j--)
		    if(a[j]!=b[j]){
		    	r=j;
		    	break;
			}
		for(int j=l;j<=r;j++){
			c[k]=a[j];
			k++;
		}
		for(int m=0;m<=s[i].vc.size();m++)
			    s[i].vc[m]='\0';
		for(k--;k>=0;k--){
			
			s[i].vc[k]=c[k];
		}
		k=0;
		c.clear();
		for(int j=l;j<=r;j++){
			c[k]=b[j];
			k++;
		}
		for(int m=0;m<=s[i].vc.size();m++)
			    s[i].ve[m]='\0';
		for(k--;k>=0;k--){
			s[i].ve[k]=c[k];
		}
	}
	for(int i=1;i<=n;i++){
		a=t[i].vc;
		b=t[i].ve;
		r=0;
		l=0;
		k=0;
		for(int j=0;j<t[i].vc.size();j++)
		    if(a[j]!=b[j]){
		    	l=j;
		    	break;
			}
		for(int j=t[i].vc.size()-1;j>=0;j--)
		    if(a[j]!=b[j]){
		    	r=j;
		    	break;
			}
		for(int j=l;j<=r;j++){
			c[k]=a[j];
			k++;
		}
		for(int m=0;m<=t[i].vc.size();m++)
				t[i].vc[m]='\0';
		for(k--;k>=0;k--){
			
			t[i].vc[k]=c[k];
		}
		k=0;
		c.clear();
		for(int j=l;j<=r;j++){
			c[k]=b[j];
			k++;
		}
		for(int m=0;m<=t[i].ve.size();m++)
			t[i].ve[m]='\0';
		for(k--;k>=0;k--){
			
			t[i].ve[k]=c[k];
		}
	}
	for(int i=1;i<=n;i++)
		cout<<s[i].vc<<" "<<s[i].ve<<'\n';
	for(int i=1;i<=q;i++)
		cout<<t[i].vc<<" "<<t[i].ve<<'\n';
    for(int i=1;i<=q;i++){
    	ans=0;
    	for(int j=1;j<=n;j++)
    	    a=t[i].vc;
    	    b=s[j].vc;
    	    c=t[i].ve;
    	    d=s[j].ve;
    	    if(a==b&&c==d){
    	    	ans++;
			}
		cout<<ans<<' ';
	}
	return 0;
}
