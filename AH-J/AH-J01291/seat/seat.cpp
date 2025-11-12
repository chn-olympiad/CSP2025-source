 #include<bits/stdc++.h>
 using namespace std;
 int a[1000]={};
 bool cmp(int x,int y){
	 return x>y;
 }
 int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int target=a[0];
	sort(a,a+n*m,cmp);
	int ind;
	for(int i=0;i<n*m;i++){
		if(a[i]==target){
			ind=i+1;
			break;
		}
	}
	int x=(ind/n+1*(ind%n));
	int y;
	if(x%2==0){
		y=n-(ind%n)+1;
	}else{
		if(ind%n==0){
			y=n;
		}else{
			y=ind%n;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
 
