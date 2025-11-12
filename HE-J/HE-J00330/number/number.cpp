#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s; 
	vector<int> S;
    cin>>s;
    for(int i =0;i<s.size();i++){
    	if(s[i]>=48 && s[i]<=58){
    		 S.push_back(int(s[i]-48)); 
		}
	}
	for(int i =0;i<S.size();i++){
		for(int j=i;j<S.size();j++){
			if(S[i] < S[j]){
				swap(S[i],S[j]);
			}	
		}
	}
	for(int i=0;i<S.size();i++){
		printf("%d",S[i]); 
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
