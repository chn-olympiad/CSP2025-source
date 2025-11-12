#include<bits/stdc++.h>
using namespace std;
string k1,s1;
char t[500010][500];
long long n,k,s[500010];
long long i,a[500010],q,p,x,z,j,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    ans=0;
    for(i=1;i<=n;i++){
	    cin>>a[i];
	    if(a[i]==k){
		    ans++;
		    a[i]=-1;	
		}else{
		    q=0;
		    p=a[i];
		    while(p!=0){
			    q++;
			    t[i][q]=p%2+'0';
			    p=p/2;	
			}
			s[i]=q;	
		}	
	}
	k1=" ";
    while(k!=0){
		k1=k1+(char)((k%2)+'0');
		k=k/2;
	}
	for(i=1;i<=n;i++){
		if(a[i]==-1){
			continue;
		}
	    for(j=i+1;j<=n;j++){
			if(a[j]==-1){
				break;
			}
			s1=" ";
			for(x=1;x<=s[i];x++){
			    s1=s1+t[i][x];
			}
			q=s[i];
			for(x=i+1;x<=j;x++){
				for(z=1;z<=q;z++){
					if(s1[z]!=t[x][z]){
					    s1[z]='1';	
					}else{
						s1[z]='0';
					}
				}
				for(z=q+1;z<=s[x];z++){
					s1=s1+t[x][z];
					q++;
				}
			}
			if(s1==k1){
			    ans++;
			    i=j;
			    break;	
			}
		}	
	}
	cout<<ans<<endl;
    return 0;
}
