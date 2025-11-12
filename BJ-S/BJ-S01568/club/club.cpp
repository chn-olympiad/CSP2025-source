#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n;
long long sum;
int A[N],B[N],C[N];
int a,b,c;
int BC[N],AC[N],AB[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        a=0,b=0,c=0;
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>A[i]>>B[i]>>C[i];
            if(A[i]>=B[i]&&A[i]>=C[i]){
                a++;
                sum+=A[i];
                BC[a]=A[i]-max(B[i],C[i]);
            }else if(B[i]>=A[i]&&B[i]>=C[i]){
                b++;
                sum+=B[i];
                AC[b]=B[i]-max(A[i],C[i]);
            }else{
                c++;
                sum+=C[i];
                AB[c]=C[i]-max(B[i],A[i]);
            }
        }
        /*
        cout<<"\nnabc:"<<n<<" "<<a<<" "<<b<<" "<<c<<"\n\n";
        for(int i=1;i<=a;i++)cout<<BC[i]<<" ";
        cout<<endl;
        for(int i=1;i<=b;i++)cout<<AC[i]<<" ";
        cout<<endl;
        for(int i=1;i<=c;i++)cout<<AB[i]<<" ";
        cout<<endl;
        */



        if(2*a>n){
            sort(BC+1,BC+a+1);
            for(int i=0;2*(a-i)>n;i++){
                //cout<<" BC ";
                sum-=BC[i+1];
            }cout<<sum<<endl;
        }else if(2*b>n){
            sort(AC+1,AC+b+1);
            //cout<<"xxxxx AC::";
            //for(int i=1;i<=b;i++)cout<<AC[i]<<" ";
            for(int i=0;2*(b-i)>n;i++){
                //cout<<" AC "<<AC[i+1]<<" ";
                sum-=AC[i+1];
            }cout<<sum<<endl;
        }
        else if(2*c>n){
            sort(AB+1,AB+c+1);
            for(int i=0;2*(c-i)>n;i++){
                    //cout<<" AB "<<AB[i]<<" ";
                sum-=AB[i+1];
            }cout<<sum<<endl;
        }
        else{
            cout<<sum<<endl;
        }
    }fclose(stdin);
    fclose(stdout);


return 0;
}
