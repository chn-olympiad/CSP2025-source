
#include <bits/stdc++.h>
using namespace std;
long long n,q,num,k,t,m;
string s1[500000],s2[500000],s3,s4,s5,s6;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>s5>>s6;
		for(int j=0;j<n;j++){
			s3=s5;
			s4=s6;
			k=s3.find(s1[j]);
			t=s4.find(s2[j]);
			m=max(k,t);
			if(k>-1&&t>-1&&s3.find(s1[j],m)==s4.find(s2[j],m)){
				int o=s1[j].size();
				for(int l=m;l<m+o;l++){
					s3[l]=s2[j][l-m];
				}
				if(s3==s4)
				num++;
			}
		}
		cout<<num<<endl;
		num=0;
	}
	return 0;
}
