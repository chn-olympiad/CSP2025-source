#include<bits/stdc++.h>
using namespace std;
int inc(string s1,string s2){
	int count=0;
	for(int i=0;i<s1.length();i++){
		if(s1[i]==s2[0]){
			count=0;
			while(s1[count+i]==s2[count]&&count<s1.length()){
				if(i-count==s2.length()-1){
					return i;
				}
				count++;
			}
		}
		i+=count;
	}
	return -1;
}

int n,q;
string s[200001][2];
string t[200001][2];
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		for(int k=1;k<=n;k++){
			if(inc(t[i][0],s[k][0])>-1){
				string s1="";
				for(int j=0;j<t[i][0].length();j++){
					if(j==inc(t[i][0],s[k][0])){
						s1+=s[k][1];
						j+=s[k][1].length()-1;
					}else{
						s1+=t[i][0][j];
					}
				}
				if(s1==t[i][1]){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
} 
