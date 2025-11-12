#include<iostream>
using namespace std;
int n,q,s;
string s1[5000005],s2[5000005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		s=0;
		cin>>t1>>t2;
		for(int j=0;j<n;j++){
			if(t1==s1[i]||t1==s2[i]||t2==s1[i]||t2==s2[i]){
				s+=2;
			}
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
