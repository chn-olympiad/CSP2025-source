#include<bits/stdc++.h>
using namespace std;
char ans[1000010];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string sum;
	getline(cin,sum);
	int tmp=1;
	for(int i=0;i<sum.size();i++){
		if(sum[i]>='0'&&sum[i]<='9'){
			ans[tmp]=sum[i];
			tmp++;
		}
	}
	tmp--;
	sort(ans+1,ans+tmp+1,cmp);
	for(int i=1;i<=tmp;i++){
		cout<<ans[i];
	}
	return 0;
} 
