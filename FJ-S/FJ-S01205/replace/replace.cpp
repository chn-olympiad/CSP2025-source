#include<bits/stdc++.h>
using namespace std;
string s[200005][2],ques[200005][2],cha[200005];
int sum=0,n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=1;j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		sum=0;
		cin>>ques[i][0]>>ques[i][1];
		if(ques[i][0].size()!=ques[i][1].size()){
			cout<<sum;
		}else if(ques[i][0].size()==1){
			for(int j=1;j<=n;j++){
				if(s[j][0]==ques[i][0] && s[j][1]==ques[i][1]){
					sum++;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(s[j][0]==ques[i][0] && s[j][1]==ques[i][1]){
					sum++;
				}
			}
		}
		cout<<sum;
	}

	return 0;
} 
