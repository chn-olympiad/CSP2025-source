#include<bits/stdc++.h>
using namespace std;
int a[1000005]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int c=s.size(),q=0;
    for(int i=0;i<c;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[q]=s[i]-'0';
			q++;
		}
	}
	sort(a,a+q);
	for(int i=q-1;i>=0;i--){
		cout<<a[i];
	}
    return 0;
}
