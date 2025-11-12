#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long n,q;
string s1[600005],s2[600005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(long long i=0;i<q;i++){
		long long ans=0;
		string a="",b="";
		cin>>a>>b;
		long long z=b.length(),y=0;
		for(long long j=0;j<b.length();j++){
			if(j>=a.length()){
				z=min(z,j);
				y=max(y,j);
			}
			else if(a[j]!=b[j]){
				z=min(z,j);
				y=max(y,j);
			}
		}
		for(long long j=0;j<n;j++){
			//cout<<j<<endl;
			long long pd=0,tpd=0,zz=0;
			if(a.length()>=s1[j].length()){
				//cout<<a<<endl<<s1[j]<<endl;
				for(long long k=0;k+s1[j].length()<=a.length();k++){
					//cout<<s1[j][0]<<" "<<a[k]<<endl;
					if(s1[j][0]==a[k]){
						pd=0;
						for(long long l=0;l<s1[j].length();l++){
							if(s1[j][l]!=a[k+l]){
								pd=1;
								break;
							}
							//cout<<s1[j][l]<<" "<<a[k+l]<<endl;
						}
						if(!pd){
							tpd=1;
							zz=k;
							break;
						}
					}
				}
			}
			if(tpd){
				///cout<<i<<"111"<<endl;
				long long ttpd=0,gj=s2[j].length();
				string ta=a;
				for(long long k=zz+s1[j].length();k<=a.length();k++){
					ta[k+gj]=ta[k];
				}
				for(long long k=zz;k<zz+s2[j].length();k++){
					ta[k]=s2[j][k-zz];
				}
				for(long long k=zz+s2[j].length();k<=b.length();k++){
					ta[k]=ta[zz+s1[j].length()+gj+k-zz-s2[j].length()];
					//cout<<ta[k]<<" "<<j<<" "<<s2[j]<<endl;
				}
				for(long long k=0;k<max(a.length(),b.length());k++){
					//cout<<b[k]<<" "<<ta[k]<<endl;
					//cout<<b[k]<<" "<<ta[k]<<endl<<k<<" "<<zz+s2[j].length()<<endl;
					if(b[k]!=ta[k]){
						ttpd=1;
						break;
					}
				}/**/
				if(!ttpd&&zz<=z&&zz+s2[j].length()>y){
					//cout<<s1[j]<<endl<<s2[j]<<endl<<zz<<" "<<z<<" "<<zz+s2[j].length()<<" "<<y<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}

