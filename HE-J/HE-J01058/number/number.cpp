#include<bits/stdc++.h>

using namespace std;
string s;
int d;
int r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin >> s;
	int l=s.size();
	int a[l];
	for(int i=0;i<=l;i++){
		if(s[i]=='0'){
			d++;
			a[d]=0;
		}if(s[i]=='1'){
			d++;
			a[d]=1;
			r++;
		}if(s[i]=='2'){
			d++;
			a[d]=2;
			r++;
		}if(s[i]=='3'){
			d++;
			a[d]=3;
			r++;
		}if(s[i]=='4'){
			d++;
			a[d]=4;
			r++;
		}if(s[i]=='5'){
			d++;
			a[d]=5;
			r++;
		}if(s[i]=='6'){
			d++;
			a[d]=6;
			r++;
		}if(s[i]=='7'){
			d++;
			a[d]=7;
			r++;
		}if(s[i]=='8'){
			d++;
			a[d]=8;
			r++;
		}if(s[i]=='9'){
			d++;
			a[d]=9;
			r++;
		}
	}
	sort(a+1,a+d+1,cmp);
	if(r==0){
		cout << 0;
		return 0;
	}
	for(int i=1;i<=d;i++){
		cout << a[i];
	}
	return 0;
} 
