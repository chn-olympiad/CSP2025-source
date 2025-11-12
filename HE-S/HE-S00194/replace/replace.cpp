#include<bits/stdc++.h>
using namespace std;
struct pl{
	string bf,af;
} eh[200050];
struct pc{
	string pb,aw;
} qt;
int a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)cin>>eh[i].bf>>eh[i].af;
	while(b--){
		long long y=0;
		cin>>qt.pb>>qt.aw;
		if(qt.pb.length()!=qt.aw.length()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=a;i++){
			if(qt.pb==eh[i].bf&&qt.aw==eh[i].af)y++;
		}
		long long t=0,p=qt.aw.length();
		while(p--){
			if(qt.pb[t]==qt.aw[t]){
				qt.pb.erase(t,t+1);
				qt.aw.erase(t,t+1);
			}else t++;
		}
		for(int i=1;i<=a;i++){
			if(qt.pb==eh[i].bf&&qt.aw==eh[i].af)y++;
		}
		cout<<y<<endl;
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
