#include <bits/stdc++.h>
using namespace std;

int a[1000005], sum;
string s;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	for(int i = 0;i <= s.length() - 1; i++){
		if(s[i] == '1'){
			sum++;
			a[sum] = 1;
		}else if(s[i] == '2'){
			sum++;
			a[sum] = 2;
		}else if(s[i] == '3'){
			sum++;
			a[sum] = 3;
	    }else if(s[i] == '4'){
			sum++;
			a[sum] = 4;
	    }else if(s[i] == '5'){
			sum++;
			a[sum] = 5;
	    }else if(s[i] == '6'){
			sum++;
			a[sum] = 6;
	    }else if(s[i] == '7'){
			sum++;
			a[sum] = 7;
	    }else if(s[i] == '8'){
			sum++;
			a[sum] = 8;
	    }else if(s[i] == '9'){
			sum++;
			a[sum] = 9;
	    }else if(s[i] == '0'){
	    	sum++;
	    	a[sum] = 0;
		}
	}
	
	sort(a + 1,a + sum + 1,cmp);
	
	for(int i = 1;i <= sum; i++){
		cout << a[i];
	}
	
	return 0;
} 
