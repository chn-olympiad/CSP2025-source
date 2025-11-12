#include<bits/stdc++.h>
using namespace std;
int aaa[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin>>a;
	
	for(int i=0;i<a.length();i++){
		
        if(int (a[i])>=48 && int(a[i])<=58){
            aaa[int(a[i])-48]=aaa[int(a[i])-48]+1;
        }
	}
	for(int i=9;i>=0;i--){
        if(aaa[i]!=0){
            for(int j=0;j<aaa[i];j++){
                cout<<i;
            }
        }
	}
	return 0;
}
