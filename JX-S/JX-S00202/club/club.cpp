#include<iostream>
#include<vector>
using namespace std;
struct stu{
    int a;
    int b;
    int c;
};
stu student;
vector<stu> arr;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        long long a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12;
        long long a13,a14,a15,a16,a17,a18,a19,a20;
        arr.clear();
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>student.a>>student.b>>student.c;
            arr.push_back(student);
        }
        if(n==2){
            a1=arr[0].a+arr[1].b;
            a2=arr[0].a+arr[1].c;
            a3=arr[0].b+arr[1].a;
            a4=arr[0].b+arr[1].c;
            a5=arr[0].c+arr[1].a;
            a6=arr[0].c+arr[1].b;
            cout<<max(max(max(a1,a2),max(a3,a4)),max(a5,a6))<<endl;
        }
        if(n==4){//2
            a1=arr[0].a+arr[1].a+arr[2].b+arr[3].b;
            a2=arr[0].a+arr[1].a+arr[2].b+arr[3].c;
            a3=arr[0].a+arr[1].a+arr[2].c+arr[3].b;
            a4=arr[0].a+arr[1].a+arr[2].c+arr[3].c;

            a5=arr[0].a+arr[1].b+arr[2].a+arr[3].b;
            a6=arr[0].a+arr[1].b+arr[2].a+arr[3].c;
            a7=arr[0].a+arr[1].b+arr[2].b+arr[3].a;
            a8=arr[0].a+arr[1].b+arr[2].b+arr[3].c;
            a9=arr[0].a+arr[1].b+arr[2].c+arr[3].a;
            a10=arr[0].a+arr[1].b+arr[2].c+arr[3].b;
            a11=arr[0].a+arr[1].b+arr[2].c+arr[3].c;

            a12=arr[0].a+arr[1].c+arr[2].a+arr[3].b;
            a13=arr[0].a+arr[1].c+arr[2].a+arr[3].c;
            a14=arr[0].a+arr[1].c+arr[2].b+arr[3].a;
            a15=arr[0].a+arr[1].c+arr[2].b+arr[3].c;
            a16=arr[0].a+arr[1].c+arr[2].c+arr[3].a;
            a17=arr[0].a+arr[1].c+arr[2].c+arr[3].b;

            a18=arr[0].b+arr[1].a+arr[2].b+arr[3].c;
            a19=arr[0].b+arr[1].a+arr[2].c+arr[3].b;
            a20=arr[0].b+arr[1].a+arr[2].c+arr[3].c;
            long long a6m1=max(max(max(a1,a2),max(a3,a4)),max(a5,a6));
            long long a6m2=max(max(max(a7,a8),max(a9,a10)),max(a11,a12));
            long long a6m3=max(max(max(a13,a14),max(a15,a16)),max(a17,a18));
            long long a6m4=max(a19,a20);
            cout<<max(max(a6m1,a6m2),max(a6m3,a6m4))<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
