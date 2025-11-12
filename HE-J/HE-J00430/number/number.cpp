#include <bits/stdc++.h>
using namespace std;
long long l[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string ss;
	cin>>ss;
	long long mysi=ss.length();
	long long numeri=0;
//	cout<<mysi;
	for(long long i=0; i<mysi; i++){
//		cout<<"ss=\""<< ss<<"\", ss[i]='"<<ss[i]<<"'\n"; 
		if(ss[i]>='0' && ss[i]<='9'){
			l[ss[i]-'0']++;
//			cout<<"ss[i]-'0'="<<ss[i]-'0'<<endl;
			numeri++;
//			cout<<"l[ss[i]-'0']="<<l[ss[i]-'0']<<endl;
		}
	}
	int onout=9;
	while(l[onout]==0){
		onout--;
	}
//	cout<<"onout="<<onout<<endl<<"l[onout]="<<l[onout]<<endl;
	while(onout>=0){
		if(l[onout]==0){
			while(l[onout]==0){
				onout--;
			}
		}else{
			cout<<onout;
			l[onout]--;
		}
	}
	return 0;
}
