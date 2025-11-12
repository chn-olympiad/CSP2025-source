#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int c,r,a[105][105];
	vector<int> b(1);
	cin>>c>>r;//列和行
	for(int i=1;i<=c;i++){
		for(int j =1;j<=r;j++){
			cin>>a[i][j];
			b.push_back(a[i][j]);
		}
	}
	int num = a[1][1];
	int s;
	for(int i=1;i<b.size();i++){
		for(int j =i;j<b.size();j++){
			if(b[i]<b[j]){
				swap(b[i],b[j]);
			}
		}		
	}
	for(int i=1;i<b.size();i++){
		if(b[i]==num){
			s = i;
		} 
	}
	if(s>r){
		int r1 = s%r;//长度 
		if(c%2==1){
			r1=r1;
		}else{
			if(r==2){
				if(r1==1){
					r1 = 2;
				}else{
					r1 = 1;
				}
			}else{
				int mid = r-r1-r1;
				r1 = r-r1+mid;	
			}
		}
		int c1 = s/r+1;
		cout<<c1<<" "<<r1;
	}else{
		cout<<"1"<<" "<<s;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

