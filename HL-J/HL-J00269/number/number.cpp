#include<bits/stdc++.h>
#include<vector>
using namespace std;//Good luck!
string s;
int arr[1000005];
vector<int> output;
bool vis[1000005];
int fun(char c){
	if(c=='0')return 0;
	else if(c=='1')return 1;
	else if(c=='2')return 2;
	else if(c=='3')return 3;
	else if(c=='4')return 4;
	else if(c=='5')return 5;
	else if(c=='6')return 6;
	else if(c=='7')return 7;
	else if(c=='8')return 8;
	else if(c=='9')return 9;
	else return c;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)arr[i]=fun(s[i]);
	for(int i=0;i<s.size();i++) if(arr[i]>9)vis[i]=true;
	for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==9){
			output.push_back(9);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==8){
			output.push_back(8);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==7){
			output.push_back(7);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==6){
			output.push_back(6);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==5){
			output.push_back(5);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==4){
			output.push_back(4);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==3){
			output.push_back(3);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==2){
			output.push_back(2);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==1){
			output.push_back(1);
			vis[i]=true;
		}
	}for(int i=0;i<s.size();i++){
		if(vis[i]==false && arr[i]==0){
			output.push_back(0);
			vis[i]=true;
		}
	}
	for(int i=0;i<output.size();i++)cout<<output[i];
	return 0;
}
//	Long live the CCF CSP-J2 in 2025!	Sieg heil!
