#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans[1005];
    int I=0;
    for(int i=0;;i++){
		if(s[i]==0) break;
        if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='0') ans[I]=0;
            else if(s[i]=='1') ans[I]=1;
            else if(s[i]=='2') ans[I]=2;
            else if(s[i]=='3') ans[I]=3;
            else if(s[i]=='4') ans[I]=4;
            else if(s[i]=='5') ans[I]=5;
            else if(s[i]=='6') ans[I]=6;
            else if(s[i]=='7') ans[I]=7;
            else if(s[i]=='8') ans[I]=8;
            else if(s[i]=='9') ans[I]=9;
            I++;
        }
    }
    for(int i=0;i<I;i++){
        for(int j=1;j<=i;j++){
			if(ans[i]==9){
				int t=ans[0];
				ans[0]=9;
				ans[1]=t;
				continue;
			}else if(ans[i]>ans[i-j]){
                int t;
                t=ans[i-j];
                ans[i-j]=ans[i];
                ans[i]=t;
            }
        }}
    for(int i=0;i<I;i++){
		cout<<ans[i];
	}
    return 0;
}
