#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
    int a[100005],cnt=0;
	cin >> s;
	int b=s.length();
	if(b==1){
		cout << s;
		return 0;
	}
	for(int i=0;i<b;i++){
		if(s[i]=='0'){
		    a[i]=0;
		    cnt++;
		    continue;
		}else if(s[i]=='1'){
			a[i]=1;
		    cnt++;
		    continue;
		}else if(s[i]=='2'){
			a[i]=2;
		    cnt++;
		    continue;
		}else if(s[i]=='3'){
			a[i]=3;
		    cnt++;
		    continue;
		}else if(s[i]=='4'){
			a[i]=4;
		    cnt++;
		    continue;
		}else if(s[i]=='5'){
			a[i]=5;
		    cnt++;
		    continue;
		}else if(s[i]=='6'){
			a[i]=6;
		    cnt++;
		    continue;
		}else if(s[i]=='7'){
			a[i]=7;
		    cnt++;
		    continue;
		}else if(s[i]=='8'){
			a[i]=8;
		    cnt++;
		    continue;
		}else if(s[i]=='9'){
			a[i]=9;
		    cnt++;
		    continue;
		}
	}
	sort(a,a+b,cmp);
	for(int i=0;i<cnt;i++){
		cout << a[i];
	}
	return 0;
} 
