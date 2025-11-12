#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    //a1=smallr score
    int student_count=n*m;
    vector<int> student_scores;
    for (int i=1;i<=student_count;i++){
        int score_input;
        cin>>score_input;
        student_scores.push_back(score_input);
    }

    //sort
    int ith=0;
    for (int i=0;i<student_scores.size();i++){
        if (student_scores[ith] > student_scores[i]){
            ith=i;
        }
        swap(student_scores[i],student_scores[ith]);
    }

    int zw[n+2][m+2]={},a=0,a1=0;
    int ll,ss;
    for (int i=0;i<student_scores.size();i++){
        if (m<=i){
            if (i==0){
                ll=i;
                ss=a1+1;
            }
            zw[a][a+1]=student_scores[i];
            a++;
        }else{
            if (n<=a){
                zw[i+1][a1]=student_scores[i];
            } else {
                if (i==0){
                    ll=i;
                    ss=a1;
                }
                zw[i][a1]=student_scores[i];
            }
            a1++;
        }
    }
    /*for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<zw[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<ll+1<<" "<<ss+1;
    return 0;
}
