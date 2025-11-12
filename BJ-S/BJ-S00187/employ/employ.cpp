#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int n, m;
struct meet{
    char hard;
    int bear;
}employ[MAXN];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        cin >> employ[i].hard;
    }
    for(int i = 0; i < n; i ++){
        cin >> employ[i].bear;
    }
    int num = 0;
    int failed = 0;
    for(int i = 0; i < n; i ++){
        if(employ[i].hard == '1' || failed >= employ[i].bear) failed ++;
        else num ++;
    }
    if(num < m){
		num = 0, failed = 0;
		for(int i = 0; i < n; i ++){
			if(i == 0) num ++;
			else if(employ[i].hard == '1' || failed >= employ[i].bear) failed ++;
			else num ++;
		}
	}
	cout << num;
}
