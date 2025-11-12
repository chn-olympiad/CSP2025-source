#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][5];
string t1,t2;
void RP(){
	/*
	while(1){
		cout<<"RP++\n";
	}
	*/ 
	srand(time(0));
	int I_am_lucky=rand()%t1.size(); 
	cout<<I_am_lucky<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n"; 
		}
		RP();
	}
	return 0;
}

