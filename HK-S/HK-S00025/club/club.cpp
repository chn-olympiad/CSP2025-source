int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    long long t, n, max=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        long long a1[10], a2[10];
        max=0;
        cin>>a1[1]>>a1[2]>>a1[3];
        cin>>a2[1]>>a2[1]>>a2[2];
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(i!=j){
                    if(a1[i]+a2[j]>max) max=a1[i]+a2[j];
                }
            }
        }
    }
    cout<<max;
    return 0;
}
