#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int result=0;
	cin>>n;
	int stick[3];
	for(int i=0;i<3;i++){
		cin>>stick[i];
	}
	sort(stick,stick+3,cmp);
	if(stick[0]+stick[1]+stick[2]>stick[0]*2){
		result+=1;
	}else{
		result+=0;
	}
	cout<<result;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
