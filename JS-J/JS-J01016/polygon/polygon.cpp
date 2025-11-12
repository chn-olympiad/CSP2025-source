#include<bits/stdc++.h>
using namespace std;

const int N=5005;
int arr[N];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    sort(arr+1, arr+n+1);
    int mx=0,cnt=0,sum=0;
    if(n==3){
        mx=arr[n];
        sum=arr[1]+arr[2]+arr[3];
        if(sum>mx*2){
            cout<<"1";
            return 0;
        } else {
            cout<<"0";
            return 0;
        }
    }
    if(n>3 && n<=10){
        if(n>=3)
            for(int a=1; a<=n; a++){
                for(int b=a+1; b<=n; b++){
                    for(int c=b+1; c<=n; c++){
                        sum=arr[a]+arr[b]+arr[c];
                        mx=arr[c];
                        if(sum>2*mx) cnt++;
                    }
                }
            }
        if(n>=4)
            for(int a=1; a<=n; a++)
                for(int b=a+1; b<=n; b++)
                    for(int c=b+1; c<=n; c++)
                        for(int d=c+1; d<=n; d++){
                            sum=arr[a]+arr[b]+arr[c]+arr[d];
                            mx=arr[d];
                            if(sum>2*mx) cnt++;
                        }

        if(n>=5)
            for(int a=1; a<=n; a++)
                for(int b=a+1; b<=n; b++)
                    for(int c=b+1; c<=n; c++)
                        for(int d=c+1; d<=n; d++)
                            for(int e=d+1; e<=n; e++){
                                sum=arr[a]+arr[b]+arr[c]+arr[d]+arr[e];
                                mx=arr[e];
                                if(sum>2*mx) cnt++;
                            }

        if(n>=6)
            for(int a=1; a<=n; a++)
                for(int b=a+1; b<=n; b++)
                    for(int c=b+1; c<=n; c++)
                        for(int d=c+1; d<=n; d++)
                            for(int e=d+1; e<=n; e++)
                                for(int f=e+1; f<=n; f++){
                                    sum=arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f];
                                    mx=arr[f];
                                    if(sum>2*mx) cnt++;
                                }

        if(n>=7)
            for(int a=1; a<=n; a++)
                for(int b=a+1; b<=n; b++)
                    for(int c=b+1; c<=n; c++)
                        for(int d=c+1; d<=n; d++)
                            for(int e=d+1; e<=n; e++)
                                for(int f=e+1; f<=n; f++)
                                    for(int g=f+1; g<=n; g++){
                                        sum=arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g];
                                        mx=arr[g];
                                        if(sum>2*mx) cnt++;
                                    }

        if(n>=8)
            for(int a=1; a<=n; a++)
                for(int b=a+1; b<=n; b++)
                    for(int c=b+1; c<=n; c++)
                        for(int d=c+1; d<=n; d++)
                            for(int e=d+1; e<=n; e++)
                                for(int f=e+1; f<=n; f++)
                                    for(int g=f+1; g<=n; g++)
                                        for(int h=g+1; h<=n; h++){
                                            sum=arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g]+arr[h];
                                            mx=arr[h];
                                            if(sum>2*mx) cnt++;
                                        }

        if(n>=9)
            for(int a=1; a<=n; a++)
                for(int b=a+1; b<=n; b++)
                    for(int c=b+1; c<=n; c++)
                        for(int d=c+1; d<=n; d++)
                            for(int e=d+1; e<=n; e++)
                                for(int f=e+1; f<=n; f++)
                                    for(int g=f+1; g<=n; g++)
                                        for(int h=g+1; h<=n; h++)
                                            for(int i=h+1; i<=n; i++){
                                                sum=arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g]+arr[h]+arr[i];
                                                mx=arr[i];
                                                if(sum>2*mx) cnt++;
                                            }

        if(n>=10){
            sum=arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9]+arr[10];
            mx=arr[10];
            if(sum>2*mx){
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    return 0;
}
