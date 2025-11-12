 #include<bits/stdc++.h>
 using namespace std;
 const int N=1e6+5;long long n,m;
 struct ap
 {
 	int a;
 	long long fs;
 }a[N];
 bool cmps(ap a,ap b)
 {
 	return a.fs>b.fs;
 }
 int main()
 {
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
// 	string s;
 	cin>>n>>m;
 	long long t=m*n;
 	for(long long i=0;i<t;i++)
 	{
 	cin>>a[i].fs;
 	a[i].a=i;
	}
	sort(a,a+t,cmps);
	for(long long i=0;i<t;i++)
 	{
	if(a[i].a==0)
	{
		cout<<(i/n)+1<<" "<<(((i/n)+1)%2?(i%n)+1:(n-(i%n)));
		return 0;
	}
	}
// 	for(long long i=0;i<t;i++)
// 	{
// 	cout<<a[i].fs<<"\n";
//	}
	return 0;
 }
