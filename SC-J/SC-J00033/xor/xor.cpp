#include<bits/stdc++.h>
using namespace std;
int n,k;
int r[500001];
int value[500001];
int anses[500001][2];
int ans = 0;
bool isReapted(int s1,int s2,int e1,int e2){
	if (s1 == -1 || s2 == -1 || e1 == -1 || e2 == -1){
		return false;
	}
	int start = min(s1,s2);
	int end = max(e1,e2);
	for (int i = start;i < end;i++){
		if (s1 <= i && i <= e1 && s2 <= i && i <= e2){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt = 0;
	for (int i = 0;i < n;i++){
		cin>>r[i];
		
	}
	
	
	if (n == 1){
		if (r[0] == 1){
			cout<<0;
			return 0;
		}
	}
	else if (n == 2){
		if (r[0] == 1 && r[1] == 1){
			cout<<1;
			return 0;
		}
	}
	
	value[0] = r[0];
	//cout<<"The value of "<<0<<" is"<<value[0]<<endl;
	for (int i = 1;i < n;i++){
		value[i] = (value[i-1] xor r[i]);
		//cout<<r[i]<<endl;
		//cout<<"The value of "<<i<<" is:"<<value[i]<<endl;
	}
	
	for (int i = 0;i < n;i++){
		for (int j = i;j < n;j++){
			if (abs(value[i] - value[j]) == k){
				anses[cnt++][0] = i;
				anses[cnt][1] = j;
			}
		}
	}
	
	for (int i = 0;i < n;i++){
		for (int j = i;j < n;j++){
			if (isReapted(anses[i][0],anses[j][0],anses[i][1],anses[j][1])){
				if (anses[i][1] - anses[i][0] >= anses[j][1] - anses[j][0]){
					anses[i][1] = -1;
					anses[i][0] = -1;
				}
				else{
					anses[j][1] = -1;
					anses[j][0] = -1;
				}
			}
		}
	}
	for (int i = 0;i < n;i++){
		if (anses[i][0] != -1 && anses[i][1] != -1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}