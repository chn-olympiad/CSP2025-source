#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l=0,h=0,tmp,littleR,R_;
    vector<int> s={};
    cin >> n >> m;
    cin >> tmp;
    littleR=tmp;
    s.push_back(tmp);
    for(int i=1;i<n*m;i++){
        cin >> tmp;
        s.push_back(tmp);
    }
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<n*m;i++){
        if(s[i]==littleR){
            R_=i+1;
        }
    }
    if(R_%n==0){
		l=R_/n;
	}else{
		l=R_/n+1;
	}
	if(R_%n==0){
		if(l%2==0){
			h=1;
		}else{
			h=n;
		}
	}else if(l%2==0){
		h=(n-(R_%n))+1;
	}else{
		h=R_%n;
	}
	cout << l << ' ' << h;
    return 0;
}
