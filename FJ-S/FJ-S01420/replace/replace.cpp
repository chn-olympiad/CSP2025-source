#include<bits/stdc++.h>
using namespace std;
int a,b;
string q1,q2,s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for (int i=0;i<a;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for (int i=0;i<b;i++){
		int sum=0;
		cin>>q1>>q2;
		for (int j=0;j<a;j++){
			if (q1.size()+s[j][1].size()!=q2.size()+s[j][0].size()){
				sum+=0;
			}
			else if(q1.find(s[j][0]) || q2.find(s[j][1])){
				sum+=0;
			}
			else{
				sum+=1;
			}
		} 
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
} 
