#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
string s;
int ans,qwq,a[1000555];
int cmp(int x,int y){
	return x>y;
} 
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			qwq++;
			a[qwq]=long(s[i]-'0');	 
//			cout<<a[qwq]<<" qwq:"<<qwq;
		}
	}
	sort(a+1,a+1+qwq,cmp);
//	cout<<qwq<<endl;
	if(qwq>0){
		string wc;
		for(int i=1;i<=qwq;i++){
			wc+=to_string(a[i]);
//			cout<<a[i]<<" ";
		}
		cout<<wc;
////		sort(a,a+qwq);
//		sort(a,a+qwq,cmp);
////		cout<<qwq; 
//		int j=1;string wc;
//		for(int i=0;i<qwq;i++){
////			cout<<j<<"\n";
////			ans=ans+(a[i]*j);
////			j*=10;
//			cout<<"\n"<<a[i]<<" ";
////			cout<<" "<<ans<<"\n";
//			wc+=to_string(a[i]);
//		}
////		cout<<ans;
//		cout<<wc;
	}
	else cout<<0;
	
	
	//我（lyx2011） C 服了 从8；30到9：38一直改，最后发现是sort写错了，啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊 
	return 0;
} 

