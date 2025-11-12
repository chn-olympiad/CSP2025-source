#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2,y,t1,t2,x,z;
	int c,c1;
	int cnt=0;
	int sum[q];
	int e=-1;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		c=s1.size(),c1=s2.size();
		for(int j=0;j<q;j++){
			cin>>t1>>t2;
			if(s1.find(y)!=4294967295){
			cnt++;
		}
		if(t1.find(y)!=4294967295&&(y==s1&&y==s2)){
			cnt++;
		}
		}
		
		e++;
		sum[e]=cnt;
		cnt==0;
		
	}
	return 0;
}
