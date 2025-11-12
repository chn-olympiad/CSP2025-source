#include<bits/stdc++.h>
using namespace std;
string ln;
long long nm[2000005];
long long tt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ln;
	for(int i=0;i<ln.size();i++){
		if(ln[i]>=48&&ln[i]<=57){
			nm[tt]=ln[i]-48;
			tt++;
		}
	}
	sort(nm+1,nm+tt+1,cmp);
	for(int i=1;i<tt;i++)cout<<nm[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
