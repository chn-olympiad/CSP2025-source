#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
char x[N];
int ans = 0;
int flag[11] = {0};
bool cmp(char x,char y){
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.length(); 
	if(len == 1){
	    cout << s << '\n';
	    return 0;
	}else{
		for(int i = 0;i < len;i ++){
		    if(s[i] >= '0' && s[i] <= '9'){
			    if(s[i] == '0'){
			    	x[i] = s[i];
				    flag[1] ++; 
				    ans ++;
			    }else if(s[i] == '1'){
			    	x[i] = s[i];
				    flag[2] ++; 
				    ans ++; 
			    }else if(s[i] == '2'){
			    	x[i] = s[i];
				    flag[3] ++;  
				    ans ++;  
			    }else if(s[i] == '3'){
			    	x[i] = s[i];
				    flag[4] ++;
				    ans ++;
			    }else if(s[i] == '4'){
			    	x[i] = s[i];
				    flag[5] ++;
				    ans ++;
			    }else if(s[i] == '5'){
			    	x[i] = s[i];
				    flag[6] ++;
				    ans ++;
			    }else if(s[i] == '6'){
			    	x[i] = s[i];
				    flag[7] ++;
				    ans ++;
			    }else if(s[i] == '7'){
			    	x[i] = s[i];
				    flag[8] ++;
				    ans ++;
			    }else if(s[i] == '8'){
			    	x[i] = s[i];
				    flag[9] ++;
				    ans ++;
			    }else if(s[i] == '9'){
			    	x[i] = s[i]; 
				    flag[10] ++;
				    ans ++; 
			    }
		    }else{
		    	break;
			}
	    }
	}
	int sum = ans;
	while(flag[1] > 2){
		sum -= (flag[1] - 2);
		flag[1] -= 2;
	}
	while(flag[2] > 2){
		sum -= (flag[2] - 2);
		flag[2] -= 2;
	}
	while(flag[3] > 2){
		sum -= (flag[3] - 2);
		flag[3] -= 2;
	}
	while(flag[4] > 2){
		sum -= (flag[4] - 2);
		flag[4] -= 2;
	}
	while(flag[5] > 2){
		sum -= (flag[5] - 2);
		flag[5] -= 2;
	}
	while(flag[6] > 2){
		sum -= (flag[6] - 2);
		flag[6] -= 2;
	}
	while(flag[7] > 2){
		sum -= (flag[7] - 2);
		flag[7] -= 2;
	}
	while(flag[8] > 2){
		sum -= (flag[8] - 2);
		flag[8] -= 2;
	}
	while(flag[9] > 2){
		sum -= (flag[9] - 2);
		flag[9] -= 2;
	}
	while(flag[10] > 2){
		sum -= (flag[10] - 2);
		flag[10] -= 2;
	}
	sort(x,x + sum,cmp);
	for(int i = 0;i < sum;i ++){
		cout << x[i];
	}
	return 0;
}
