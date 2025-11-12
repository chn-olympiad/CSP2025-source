#include<bits/stdc++.h>
using namespace std;
char arr[10000005],cnt=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            arr[cnt]=s[i];
            cnt++;
        }
	}
    sort(arr+1,arr+cnt+1,greater<int>());
    for(int i=1;i<=cnt;i++){
        cout<<arr[i];
    }
	return 0;
}
