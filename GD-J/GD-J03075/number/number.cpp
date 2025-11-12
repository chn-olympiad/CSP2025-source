#include<bits/stdc++.h>

using namespace std;

int const maxx=1e6+10;

string n;
int c[maxx],cnt1;

bool num(char x){
	if(x-'0'>=0&&x-'0'<=9){
		cnt1=x-'0';
		return true;
	}
	else{
		return false;
	}
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>n;
	int cnt=n.size(),now=1;
	
	for(int i=0;i<cnt;i++){
		if(num(n[i])){
			c[now]=cnt1;
			now++;
		}
	}
	
	sort(c+1,c+now);
	for(int i=now-1;i>0;i--){
		cout<<c[i];
	}
	cout<<endl;
	return 0;
}

