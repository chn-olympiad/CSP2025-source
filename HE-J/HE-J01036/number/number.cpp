#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long tong[10]={0,0,0,0,0,0,0,0,0,0};
	long long cnt=a.length();
	for(long long i=0;i<cnt;i++){
		if(a[i]>='0'&&a[i]<='9'){
			int t=a[i]-'0';
			tong[t]++;
		}
	}
	if(tong[1]==0&&tong[2]==0&&tong[3]==0&&tong[4]==0&&tong[5]==0&&tong[6]==0&&tong[7]==0&&tong[8]==0&&tong[9]==0){
		cout<<"0";
		return 0;
	}
    for(int j=9;j>=0;j--){
    	for(long long i=0;i<tong[j];i++){
    		cout<<j;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
