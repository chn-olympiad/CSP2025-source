#include<bits/stdc++.h>
using namespace std;
string s;
long long n[100010]={0};
int cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<97){
			if(s[i]==48){
				n[i]=0;
				cnt++;
			}else if(s[i]==49){
				n[i]=1;
				cnt++;
			}else if(s[i]==50){
				n[i]=2;
				cnt++;
			}else if(s[i]==51){
				n[i]=3;
				cnt++;
			}else if(s[i]==52){
				n[i]=4;
				cnt++;
			}else if(s[i]==53){
				n[i]=5;
				cnt++;
			}else if(s[i]==54){
				n[i]=6;
				cnt++;
			}else if(s[i]==55){
				n[i]=7;
				cnt++;
			}else if(s[i]==56){
				n[i]=8;
				cnt++;
			}else if(s[i]==57){
				n[i]=9;
				cnt++;
			}
		}
			
	}
	sort(n,n+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<n[i];
	}
	return 0;
}
