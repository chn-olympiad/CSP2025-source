nclude<bits/c++.h>
using namespace std;
int main(){
freopen(stdin,"r",xor.in);
freout(stdout,"w",xor.out);
	long long n,k,f=0,b,p=0;
	cin>>n>>k;
	long long a[n],l[35345546]
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int i=1;i<=n-2;i++){
                long long f=1;
                while(f<=n){
                        for(b=1;b<=f;b++){
                            m=a[i]+a[i+1];
	                        l[i]=a[i];
	                        l[i+1]=a[i+1];
	                }
                        for(int i=0;i<b;i++;){
                        	p=l[i]xor(l[i+1]);
                        }
                        if(p==k){
                        	f++;
                        }
                        p=0;

	}
}
}
	cout<<f;
	return 0;
}
