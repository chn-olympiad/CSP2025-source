#include<bits/stdc++.h>
using namespace std;
string s;
char arr[5000001];
int cnt=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			arr[cnt++]=s[i];
		}
	} 
	sort(arr,arr+cnt,cmp);
	for(int i=0;i<cnt;i++){
		printf("%c",arr[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
