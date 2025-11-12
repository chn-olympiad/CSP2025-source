#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
/*int Search(int* a,int Target){
	int left = 0,right = a.length();
	int mid = (left + right)/2;
	while (left < right){
		if (Target = a[mid]){
			return mid;
		}
		if (Target < a[mid]){
			right = mid - 1;
		}
		if (Target > a[mid]){
			left = mid + 1;
		}
	}
	return -1;
}*/
int Score[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int Target;
	int Num = 0;
	cin>>n>>m;
	Num = m*n;
	
	for (int i = 0;i < Num;i++){
		cin>>Score[i];
	}
	Target = Score[0];
	
	sort(Score,Score + Num,cmp);
	
	for (int i = 0;i < Num;i++){
		cout<<Score[i]<<" ";
	}
	cout<<"Target:"<<Target<<endl;
	
	
	int Loca;
	
	for (int i = 0;i < Num;i++){
		if (Score[i] == Target){
			Loca = i;
			break;
		}
	}
	
	
	int c,r;
	int h = 0;
	Loca ++;
	
	cout<<"Location:"<<Loca<<endl;
	
	if (Loca % n == 0){
		cout<<"speacial slove"<<endl;
		r = Loca / n;
		if (r % 2 == 0){
			cout<<r<<" "<<1;
		}
		else {
			cout<<r<<" "<<n;
		}
		return 0;
	}
	else {
		r = Loca / n + 1;
		h = (r - 1) * n;
	}
	if (r % 2 == 0){
		c = n - (Loca - h) % n + 1;
	}
	else{
		c = (Loca - h) % n; 
	}
	
	cout<<r<<" "<<c;
	return 0;
}