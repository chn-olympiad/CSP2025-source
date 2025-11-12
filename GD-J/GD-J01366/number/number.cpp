#include<bits/stdc++.h> 
using namespace std;
char u[1000005];
int cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>u;
	for(int i=0;u[i]!='\0';i++){
		if(u[i]=='0'){
			cnt[0]++;
		}
		if(u[i]=='1'){
			cnt[1]++;
		}
		if(u[i]=='2'){
			cnt[2]++;
		}
		if(u[i]=='3'){
			cnt[3]++;
		}
		if(u[i]=='4'){
			cnt[4]++;
		}
		if(u[i]=='5'){
			cnt[5]++;
		}
		if(u[i]=='6'){
			cnt[6]++;
		}
		if(u[i]=='7'){
			cnt[7]++;
		}
		if(u[i]=='8'){
			cnt[8]++;
		}
		if(u[i]=='9'){
			cnt[9]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cnt[i]--;
			cout<<i;
		}
	}
	return 0;
}
