#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s[1000];
	int n,m,num,sum = 0,p1 = 0,p2 = 0,p3=0,t = 0;
	num = 1;
	cin>>n>>m;
	sum = n*m;
	for(int i = 0;i<sum;i++){
		cin>>s[i];
	}for(int i = 0;i<sum;i++){
		if(s[0]<s[i]){
			num++;
		}
	}for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			p3++;
			if(num==p3){
				if(i%2==0){
					p1 = i+1;
					p2 = j+1;
					t = 1;
					break;
				}else{
					p1 = i+1;
					p2 = n-j;
					t = 1;
					break;
				}
			}else{
				continue;
			}
				
		}if(t==1){
			break;
		}else{
			continue;
		}
	}
	cout<<p1<<' '<<p2;
	fclose(stdin);
	fclose(stdout);
}