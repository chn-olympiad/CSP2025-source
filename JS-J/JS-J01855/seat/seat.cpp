 #include<bits/stdc++.h>
 using namespace std;
 int n,m,p,g;
 int a[105];
 int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	cin>>n>>m;
 	for(int i=0;i<n*m;i++){
 		cin>>a[i];
	}
 	int k=a[0];
 	sort(a,a+n*m);
 	for(int i=0;i<n*m;i++)
 		if(a[i]==k){
 			p=i;
 			break;
 		}
 	k=p%n;
 	p++;
 	g=p/n+1;
 	cout<<g<<' ';
 	if(g%2==0) cout<<n-(k+1);
	else cout<<k+1;
 	return 0;
}
