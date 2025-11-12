#include<bits/stdc++.h>
using namespace std;
int a[10];
int s[20];
int main(){
	string n;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l =0;
	int j=0;
	for(int i=0;i<n.size();i++){
		if('0'<=n[i]&&n[i]<='9'){
			if(a[i]<2){
				s[j]=n[i]-'0';
				a[n[i]-'0']++;
				l++;
				j++;
			}else{
				continue;
			}
		}
	}
	sort(s,s+l);
	if(s[l-1]==0){
        cout<<0;
        return 0;
	}
	for(int i = l-1;i>-1;i--)cout<<s[i];
	return 0;
}
