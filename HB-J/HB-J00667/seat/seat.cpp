#include<bits/stdc++.h>
using namespace std;
#define love return
#define sugary 0//神秘爱好小代码
int n, m;//n行m列
int R, num;//小R的分数,座位
int s[105];//分数
int c, r;//c列r行
bool cmp(int a,int b){
	if(a >= b) return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> s[i];
    }
    R = s[1];
    sort(s + 1, s + m * n + 1,cmp);
    
    for(int i = 1; i <= m * n; i++){
		if(s[i] == R){
			num = i;
			break;
		}
	}
	/*
	for(int i = 1; i <= m * n; i++){
		cout << s[i] << " "; 
	}
    cout << "R=" << s[num] << "\n";*/
    for(int x = 0; x <= m; x += 2){
		for(int y = 1; y <= n; y++){
			if(num == x * n + y){
				r = y;
				c = x + 1;
				break;
			}
		}
	}
    for(int x = 1; x <= m; x += 2){
		for(int y = 1; y <= n; y++){
			if(num == x * n + y){
				r = n - y + 1;
				c = x + 1;
				break;
			}
		}
	}
	/*cout << num << "\n";*/
	cout << c << ' ' << r;
    love sugary;
}
