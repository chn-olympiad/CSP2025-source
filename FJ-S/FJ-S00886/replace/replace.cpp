#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
string t1,t2;
long long sum=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		sum=0; 
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int L=s1[i].length();
			for(int j=1;j<=t1.length()-L+1;j++){
				if(t1.substr(j-1,L)==s1[i]&&t2.substr(j-1,L)==s2[i]){
					//cout<<t1<<" "<<t1.substr(0,j-1)+s2[i]+t1.substr(j+L-1,1145141)<<" "<<t2<<endl;
					if( t1.substr(0,j-1)+s2[i]+t1.substr(j+L-1,1145141)==t2 ){
						sum++;
						//cout<<t1<<" "<<t1.substr(0,j-1)+s2[i]+t1.substr(j+L-1,1145141)<<" "<<t2<<endl;
					}
				}
			}
		}
		cout<<sum<<endl;//ÔÓôÛµØ¼òµ¥Ã¶¾Ù( 
	}
	return 0;
}

