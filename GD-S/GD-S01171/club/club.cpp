#include<bits/stdc++.h>
using namespace std;

void t(){
	int n;
	cin >> n;
	int a[n][3];
	for(int i = 0;i < n;i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int sum=0;
	int s[3]={0,0,0};
	for(int i = 0;i < n;i++){
		int x[3]={0,1,2};
		if(a[i][0]<a[i][1]){
			swap(a[i][0],a[i][1]);
			swap(x[0],x[1]);
		}
		if(a[i][1]<a[i][2]){
			swap(a[i][1],a[i][2]);
			swap(x[1],x[2]);
		}
		if(a[i][0]<a[i][1]){
			swap(a[i][0],a[i][1]);
			swap(x[0],x[1]);
		}
		
		if(a[i][x[0]]>a[i][x[1]]){
			if(s[x[0]]+1<=n/2){
				s[x[0]]++;
				sum+=a[i][0];
			} else {
				if(a[i][x[1]]>a[i][x[2]]){
					if(s[x[1]]+1<=n/2){
						s[x[1]]++;
						sum+=a[i][x[1]];
					}else{
						s[x[2]]++;
						sum+=a[i][x[2]];
					}
				} else {
					if(s[x[1]]<s[x[2]]){
						s[x[1]]++;
						sum+=a[i][x[1]];
					} else if(s[x[1]]>s[x[2]]){
						s[x[2]]++;
						sum+=a[i][x[2]];
					} else {
						sum+=a[i][x[2]];
					}
				}	
			}
		} else {
			if(s[x[0]]<s[x[1]]){
				if(s[x[0]]+1<=n/2){
					s[x[0]]++;
					sum+=a[i][0];
				}else{
					s[x[2]]++;
					sum+=a[i][x[2]];
				}
			} else if(s[x[0]]>s[x[1]]){
				if(s[x[1]]+1<=n/2){
					s[x[1]]++;
					sum+=a[i][1];
				}else{
					s[x[2]]++;
					sum+=a[i][x[2]];
				}
			} else {
				if(s[x[0]]+1<=n/2){
					sum+=a[i][0];
				} else {
					s[x[2]]++;
					sum+=a[i][x[2]];
				}
			}
		}
		
	}	
	cout << sum << endl;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int temp;
	cin >> temp;
	for(int i = 0;i < temp;i++){
		t();
	}
}
